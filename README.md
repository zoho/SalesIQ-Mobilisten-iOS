[![Platform](https://img.shields.io/badge/platforms-iOS-orange.svg)](https://cocoapods.org/pods/Mobilisten)
[![SupportedLanguages](https://img.shields.io/badge/languages-Swift%20%7C%20%20ObjectiveC-green.svg)](https://www.zoho.com/salesiq/help/developer-section/ios-mobile-sdk-installation.html)
[![Version](https://img.shields.io/badge/version-10.1.6-blue.svg)](https://cocoapods.org/pods/Mobilisten)
[![Cocoapods CDI](https://github.com/zoho/SalesIQ-Mobilisten-iOS/workflows/Cocoapods%20CD/badge.svg)](https://github.com/zoho/SalesIQ-Mobilisten-iOS/actions?query=workflow%3A%22Cocoapods+CD%22)

# SalesIQ Mobilisten iOS SDK

Connect with customers at every step of their journey. Deliver the best in-app experience with Mobilisten’s live chat and voice call support. Mobilisten makes it easy for customers to reach you from any screen within your app, get their questions answered instantly, and make confident, informed decisions.  


## Installation using Cocoapods

You can integrate Mobilisten in your application using [Cocoapods](https://guides.cocoapods.org/using/getting-started.html) using the Mobilisten pod.
Here is an example Podfile where Mobilisten is included. 

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '13.0'

target 'Project Target' do
  use_frameworks!
  pod 'Mobilisten', '10.1.6'
  # Only if using audio call support
  pod 'MobilistenCalls', '1.1.0'
end
```

> Note: When using "pod MobilistenCalls", it is mandatory to add "pod Mobilisten".  


After **Mobilisten** is added to your Podfile, run the `pod install` command to complete the Installation.

## Installation using Swift Package Manager

You can now integrate Mobilisten and Mobilisten Calls with your app using SPM 🎉  [Learn More](https://github.com/zoho/SalesIQ-Mobilisten-iOS-SP)


## Getting Started

Mobilisten comes with a set of highly configurable APIs to suit your needs. Register your app's Bundle ID via the SalesIQ Console to generate the `App` and `Access` keys for Mobilisten.

## Initializing Mobilisten
Use the `ZohoSalesIQ.initWithAppKey(:accessKey:completion:)` API to initialize Mobilisten.
```swift
import Mobilisten
import MobilistenCalls // Only if using audio call support

// Initialize MobilistenCalls (only if you're using it)
ZohoSalesIQCalls.initialise() 

// Initialize Mobilisten SDK
ZohoSalesIQ.initWithAppKey("YOUR_APP_KEY", accessKey: "YOUR_ACCESS_KEY") { error in
    if error == nil {
        print("Mobilisten initialized successfully.")
    } else {
        print("Initialization failed: \(error?.message)")
    }
}
```

## API Documentation
You can find the list of all APIs and their documentation [here](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-event-delegate-v3.html) under the **API Reference** section

