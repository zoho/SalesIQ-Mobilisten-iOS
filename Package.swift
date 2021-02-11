// swift-tools-version:5.3
import PackageDescription

let version = "3.6.3"
let package = Package(
    name: "Mobilisten",
    products: [
        .library(
            name: "Mobilisten",
            targets: ["Mobilisten"]),
    ],
    targets: [
        .binaryTarget(
            name: "Mobilisten",
            url: "https://raw.githubusercontent.com/zoho/SalesIQ-Mobilisten-iOS/v\(version)/Mobilisten.zip")
    ]
)
