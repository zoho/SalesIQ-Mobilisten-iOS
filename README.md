[![Platform](https://img.shields.io/badge/platforms-iOS-orange.svg)](https://cocoapods.org/pods/Mobilisten)
[![SupportedLanguages](https://img.shields.io/badge/languages-Swift%20%7C%20%20ObjectiveC-green.svg)](https://www.zoho.com/salesiq/help/developer-section/ios-mobile-sdk-installation.html)
[![Version](https://img.shields.io/badge/version-5.4.1-blue.svg)](https://cocoapods.org/pods/Mobilisten)
[![Cocoapods CDI](https://github.com/zoho/SalesIQ-Mobilisten-iOS/workflows/Cocoapods%20CD/badge.svg)](https://github.com/zoho/SalesIQ-Mobilisten-iOS/actions?query=workflow%3A%22Cocoapods+CD%22)

# SalesIQ Mobilisten  iOS SDK 5.4.1

Connect with customers at every step of their journey. Give them the best in-app live chat experience with Mobilisten. Mobilisten enables customers to reach you from any screen on your app, get their questions answered, and make better purchase decisions.  


## Installation using Cocoapods

You can integrate Mobilisten in your application using [Cocoapods](https://guides.cocoapods.org/using/getting-started.html) using the Mobilisten pod.
Here is an example Podfile where Mobilisten is included. 

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '11.0'

target 'Project Target' do
  use_frameworks!
  pod 'Mobilisten', '5.4.1'
end
```

After **Mobilisten** is added to your Podfile, run the `pod install` command to complete the Installation.

## Installation using Swift Package Manager

You can now integrate Mobilisten with your app using SPM 🎉  [Learn More](https://github.com/zoho/SalesIQ-Mobilisten-iOS-SP)

## Manual Installation

You can find our manual integration guide [here](https://www.zoho.com/salesiq/help/developer-section/ios-mobile-sdk-installation.html)


## Getting Started

Mobilisten comes with a set of highly configurable APIs to suit your needs. Register your app's Bundle ID via the SalesIQ Console to generate the `App` and `Access` keys for Mobilisten.

## Initializing Mobilisten
Use the `ZohoSalesIQ.initWithAppKey(:accessKey:completion:)` API to initialize Mobilisten.
```swift
ZohoSalesIQ.initWithAppKey("app_key", accessKey: "access_key") { _ in
    // your code goes here
}
```

## API Documentation
You can find the list of all APIs and their documentation [here](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-event-delegate-v3.html) under the **API Reference** section.

