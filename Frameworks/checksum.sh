#!/bin/bash

# Output file to store the formatted binary target entries
OUTPUT_FILE="checksums.txt"
> "$OUTPUT_FILE"

# Define groups of framework names
mobilisten_group=("Mobilisten" "MobilistenCore" "MobilistenCallsCore" "AVCallKitBridge")
mobilisten_calls_group=("AppBridge" "AVCallKit" "AVCommonsCore" "AVCommonsVoIP" "Floatkit" "iRTCPMeeting" "MeetingClient" "MobilistenCalls" "Starscream" "TraceKit" "TraceKitCore" "UIPullDownMenuKit" "WebRTC" "WebRTCExtras" "WMSPackage" "ZIPFoundation")

# Function to check if an item is present in a given group array
function is_in_group() {
  local item=$1
  shift
  local group=("$@")
  for element in "${group[@]}"; do
    if [[ "$element" == "$item" ]]; then
      return 0
    fi
  done
  return 1
}

# Array to collect all valid binaryTarget entries
entries=()

# Iterate over all zip files in the current directory
for zip_file in *.zip; do
    [[ -e "$zip_file" ]] || continue

    name="${zip_file%.zip}"
    echo "Processing $zip_file..."

    # Compute the checksum for the zip file using Swift Package Manager
    checksum=$(swift package compute-checksum "$zip_file" 2>/dev/null)
    if [[ $? -ne 0 ]]; then
        echo "❌ Failed to compute checksum for $zip_file. Skipping..."
        continue
    fi

    # Assign the version variable depending on the group the framework belongs to
    if is_in_group "$name" "${mobilisten_group[@]}"; then
        version_var="\\(mobilisten_version)"
    elif is_in_group "$name" "${mobilisten_calls_group[@]}"; then
        version_var="\\(mobilisten_calls_version)"
    else
        echo "⚠️  $name not in known groups. Skipping..."
        continue
    fi

    # Format the binaryTarget entry for this framework
    entry=$(cat <<EOF
    .binaryTarget(
        name: "$name",
        url: "https://raw.githubusercontent.com/zoho/SalesIQ-Mobilisten-iOS/$version_var/Frameworks/$zip_file",
        checksum: "$checksum"
    )
EOF
)
    entries+=("$entry")
done

# Write the collected entries to the output file in the desired format
echo "targets: [" >> "$OUTPUT_FILE"
for i in "${!entries[@]}"; do
    if [[ $i -lt $((${#entries[@]} - 1)) ]]; then
        echo "${entries[$i]}," >> "$OUTPUT_FILE"
    else
        echo "${entries[$i]}" >> "$OUTPUT_FILE"
    fi
done
echo "]" >> "$OUTPUT_FILE"

echo "✅ Done. Output written to: $OUTPUT_FILE"
