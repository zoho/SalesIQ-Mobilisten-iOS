//
//  SIQCustomScrollView.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 07/06/23.
//

import UIKit

class SIQCustomScrollView: UIScrollView {
    
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupView()
    }
    
    //initWithCode to init view from xib or storyboard
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        setupView()
    }
    
    //common func to init our view
    private func setupView() {
        keyboardDismissMode = .onDrag
    }
    
    override func touchesShouldCancel(in view: UIView) -> Bool {
        // Dismiss the keyboard when the user touches any subview of the scroll view
        if view is UIControl {
            return true
        }
        return super.touchesShouldCancel(in: view)
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        // Dismiss the keyboard when the user touches the scroll view
        super.touchesBegan(touches, with: event)
        endEditing(true)
    }
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        // Dismiss the keyboard when the user releases their touch on the scroll view
        super.touchesEnded(touches, with: event)
        endEditing(true)
    }
}
