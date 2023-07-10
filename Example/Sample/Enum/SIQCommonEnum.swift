//
//  SIQCommonEnum.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 07/06/23.
//

import Foundation


public enum SIQToggle: String {
    case launcherVisibility
    case agentImageOnLauncher
    case supportLanguage
    
    var title: String {
        switch self {
        case .launcherVisibility:
            return "Launcher visibility:"
        case .agentImageOnLauncher:
            return "Agent image on Launcher:"
        case .supportLanguage:
            return "Support language:"
        }
    }
    
    var items: [String] {
        switch self {
        case .launcherVisibility, .agentImageOnLauncher:
            return ["Show","Hide"]
        case .supportLanguage:
            return ["EN","FR","JA"]
        }
    }
}
