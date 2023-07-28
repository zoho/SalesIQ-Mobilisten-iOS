//
//  SampleApp.swift
//  Sample
//
//  Created by Sivasankar on 25/07/23.
//

import SwiftUI

@main
struct SampleApp: App {
    init(){
        let appKey = "<#App Key#>"
        let accessKey = "<#Access Key#>"
        MobilistenImplementation.initializeSDK(appKey: appKey, accessKey: accessKey)
    }
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
    
}

