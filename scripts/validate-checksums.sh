#!/bin/bash

# Framework Checksum Validator
# This script helps validate that local framework files match release assets
# to prevent Swift Package Manager checksum issues.

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
FRAMEWORKS_DIR="$SCRIPT_DIR/../Frameworks"

echo "🔍 Validating Framework Checksums..."
echo ""

# Function to get the latest git tag
get_latest_tag() {
    git describe --tags --abbrev=0 2>/dev/null || echo ""
}

# Function to calculate checksum for a file
calc_checksum() {
    shasum -a 256 "$1" | cut -d' ' -f1
}

# Main validation
main() {
    local tag=""
    local validate_release=false
    
    # Parse arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            --tag)
                tag="$2"
                validate_release=true
                shift 2
                ;;
            --latest)
                tag=$(get_latest_tag)
                validate_release=true
                shift
                ;;
            --help)
                echo "Usage: $0 [--tag TAG_NAME] [--latest]"
                echo ""
                echo "Options:"
                echo "  --tag TAG_NAME    Validate against specific release tag"
                echo "  --latest          Validate against latest git tag"
                echo "  --help            Show this help message"
                exit 0
                ;;
            *)
                echo "Unknown option: $1"
                echo "Use --help for usage information"
                exit 1
                ;;
        esac
    done
    
    if [ ! -d "$FRAMEWORKS_DIR" ]; then
        echo "❌ Error: Frameworks directory not found at $FRAMEWORKS_DIR"
        exit 1
    fi
    
    echo "📁 Local Framework Checksums:"
    local has_files=false
    for file in "$FRAMEWORKS_DIR"/*.zip; do
        if [ -f "$file" ]; then
            has_files=true
            local basename_file=$(basename "$file")
            local checksum=$(calc_checksum "$file")
            echo "  $basename_file: $checksum"
        fi
    done
    
    if [ "$has_files" = false ]; then
        echo "❌ No framework .zip files found in $FRAMEWORKS_DIR"
        exit 1
    fi
    
    echo ""
    
    # Validate against release if requested
    if [ "$validate_release" = true ]; then
        if [ -z "$tag" ]; then
            echo "❌ Error: No tag specified or found"
            exit 1
        fi
        
        echo "🔗 Validating against release $tag..."
        echo ""
        
        local release_url="https://github.com/zoho/SalesIQ-Mobilisten-iOS/releases/download/$tag/Mobilisten.zip"
        local temp_file=$(mktemp)
        
        echo "📥 Downloading release asset..."
        if curl -L -f -o "$temp_file" "$release_url" 2>/dev/null; then
            local release_checksum=$(calc_checksum "$temp_file")
            local local_checksum=$(calc_checksum "$FRAMEWORKS_DIR/Mobilisten.zip")
            
            echo "📊 Comparison Results:"
            echo "  Local Repository: $local_checksum"
            echo "  Release Asset:    $release_checksum"
            echo ""
            
            if [ "$local_checksum" = "$release_checksum" ]; then
                echo "✅ SUCCESS: Checksums match! SPM integration should work correctly."
            else
                echo "❌ ERROR: Checksum mismatch detected!"
                echo ""
                echo "This will cause Swift Package Manager errors when users try to integrate."
                echo "Please update the local Frameworks/Mobilisten.zip to match the release asset:"
                echo ""
                echo "  curl -L -o Frameworks/Mobilisten.zip '$release_url'"
                echo ""
                exit 1
            fi
        else
            echo "❌ Error: Could not download release asset from $release_url"
            echo "Please check if the release exists and is publicly accessible."
            exit 1
        fi
        
        rm -f "$temp_file"
    fi
    
    echo ""
    echo "📋 Swift Package Manager Reference:"
    echo "Use these checksums in the SPM Package.swift file:"
    echo ""
    
    for file in "$FRAMEWORKS_DIR"/*.zip; do
        if [ -f "$file" ]; then
            local basename_file=$(basename "$file" .zip)
            local checksum=$(calc_checksum "$file")
            echo "// $basename_file: checksum: \"$checksum\""
        fi
    done
}

# Run main function with all arguments
main "$@"