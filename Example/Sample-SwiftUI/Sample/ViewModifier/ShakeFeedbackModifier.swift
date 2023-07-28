//
//  ShakeFeedbackModifier.swift
//  Sample
//
//  Created by Sivasankar on 26/07/23.
//

import SwiftUI

struct ShakeFeedbackModifier: ViewModifier {
    @Binding var shake: Bool
    func body(content: Content) -> some View {
        content
            .offset(x: shake ? -10 : 0, y: 0)
            .animation(Animation.default.repeatCount(2).speed(4),value: shake)
            .onChange(of: shake) { newValue in
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.23) {
                    shake = false
                }
            }
    }
}
