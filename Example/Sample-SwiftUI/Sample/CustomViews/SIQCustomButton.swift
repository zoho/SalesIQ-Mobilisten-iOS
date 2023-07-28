//
//  SIQCustomButton.swift
//  Sample
//
//  Created by Sivasankar on 26/07/23.
//

import SwiftUI


struct SIQCustomButton: View {
    let name: String
    let textSize:CGSize
    let corenerRadious:CGFloat = 8
    @State var isLoading = false
    var action: (_ completion: @escaping () -> Void) -> Void
    var body: some View {
        Button(action: {
            // Do something that takes a long time
            self.isLoading = true
            action {
                self.isLoading = false
            }
            
        }) {
            ZStack {
                if isLoading {
                    ProgressView()
                        .tint(.white)
                        .frame(width: textSize.width,height: textSize.height)
                    
                } else {
                    Text(name).frame(width: textSize.width,height: textSize.height)
                }
            }
        }.background(Color(UIColor.systemBlue))
            .foregroundColor(.white)
            .cornerRadius(8)
    }
}
