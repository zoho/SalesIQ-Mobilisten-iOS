// swift-tools-version:5.3
import PackageDescription

let version = "3.6.3"
let package = Package(
    name: "Mobilisten",
    platforms: [.iOS(.v10)],
    products: [
        .library(
            name: "Mobilisten",
            targets: ["Mobilisten"]),
    ],
    targets: [
        .binaryTarget(name: "Mobilisten", path: "Mobilisten.zip")
    ]
)
