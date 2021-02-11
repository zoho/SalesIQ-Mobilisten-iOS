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
        .binaryTarget(
            name: "Mobilisten",
            url: "https://raw.githubusercontent.com/zoho/SalesIQ-Mobilisten-iOS/v\(version)/Mobilisten.zip", checksum: "981bd2ea97dafef8abc80c37f65f99687896286ff4546bb09c4cbf60cf9cddbe")
    ]
)
