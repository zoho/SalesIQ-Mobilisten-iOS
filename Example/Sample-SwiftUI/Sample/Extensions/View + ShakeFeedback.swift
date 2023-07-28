//
//  View + .swift
//  Sample
//
//  Created by Sivasankar on 26/07/23.
//

import SwiftUI

extension View {
    func shakeFeedback(shake: Binding<Bool>) -> some View {
        self.modifier(ShakeFeedbackModifier(shake: shake))
    }
}
