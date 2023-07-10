//
//  SIQCustomTextField.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit

class SIQCustomTextField: UITextField {
    
    let padding = UIEdgeInsets(top: 0, left: 8, bottom: 0, right: 28)
    
    var cornerRadius: CGFloat = 5.0 {
        didSet {
            layer.cornerRadius = cornerRadius
        }
    }
    
    var borderWidth: CGFloat = 1.0 {
        didSet {
            layer.borderWidth = borderWidth
        }
    }
    
    var borderColor: CGColor = UIColor.gray.cgColor {
        didSet {
            layer.borderColor = borderColor
        }
    }
    
    var textFont: UIFont = UIFont.systemFont(ofSize: 16.0) {
        didSet {
            font = textFont
        }
    }
    
    var textFieldColor: UIColor = .white {
        didSet {
            textColor = textFieldColor
        }
    }
    
    var textFieldPlaceHolder: String = "" {
        didSet {
            placeholder = textFieldPlaceHolder
        }
    }
    
    var placeholderColor: UIColor = UIColor(named: "tertiary") ?? .gray
    
    convenience init(placeholder: String, keyboardType: UIKeyboardType = .namePhonePad) {
        self.init(frame: .zero)
        self.attributedPlaceholder = NSAttributedString(string: placeholder, attributes: [NSAttributedString.Key.foregroundColor: placeholderColor])
        self.keyboardType = keyboardType
    }
    
    override var intrinsicContentSize: CGSize {
        return CGSize(width: super.intrinsicContentSize.width, height: 44)
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupTextField()
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        setupTextField()
    }
    
    func setupTextField() {
        self.layer.cornerRadius = cornerRadius
        self.layer.borderWidth = borderWidth
        self.layer.borderColor = borderColor
        self.font = textFont
        self.textColor = textFieldColor
        self.attributedPlaceholder = NSAttributedString(string: textFieldPlaceHolder, attributes: [NSAttributedString.Key.foregroundColor: placeholderColor])
        self.clearButtonMode = .whileEditing
        self.translatesAutoresizingMaskIntoConstraints = false
        handleDarkModeChange()
    }

    func shake() {
        let animation = CAKeyframeAnimation(keyPath: "transform.translation.x")
        animation.timingFunction = CAMediaTimingFunction(name: CAMediaTimingFunctionName.linear)
        animation.duration = 0.6
        animation.values = [-10, 10, -10, 10, -5, 5, -2, 2, 0]
        layer.add(animation, forKey: "shake")
    }
    
    @objc private func handleDarkModeChange() {
        let currentInterfaceStyle = UIScreen.main.traitCollection.userInterfaceStyle
        if currentInterfaceStyle == .dark {
            self.textColor = .white
        } else {
            self.textColor = .black
        }
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        handleDarkModeChange()
    }
    
    override open func textRect(forBounds bounds: CGRect) -> CGRect {
        return bounds.inset(by: padding)
    }
    
    override open func placeholderRect(forBounds bounds: CGRect) -> CGRect {
        return bounds.inset(by: padding)
    }
    
    override open func editingRect(forBounds bounds: CGRect) -> CGRect {
        return bounds.inset(by: padding)
    }
}
