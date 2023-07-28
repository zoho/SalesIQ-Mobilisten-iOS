//
//  SIQCustomButton.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit

class SIQCustomButton: UIButton {
    
    // MARK: - Properties
    
    var title: String? {
        didSet {
            setTitle(title, for: .normal)
        }
    }
    
   internal var titleColor: UIColor = .white {
        didSet {
            setTitleColor(titleColor, for: .normal)
        }
    }
    
    var buttonBackgroundColor: UIColor = .systemBlue {
        didSet {
            backgroundColor = buttonBackgroundColor
        }
    }
    
    var cornerRadius: CGFloat = 8 {
        didSet {
            layer.cornerRadius = cornerRadius
        }
    }
    
    var font: UIFont = UIFont.systemFont(ofSize: 17, weight: .regular) {
        didSet {
            titleLabel?.font = font
        }
    }
    
    private var originalButtonTitle: String?
    private var activityIndicator: UIActivityIndicatorView!
    
    convenience init(title: String) {
        self.init(type: .system)
        setTitle(title, for: .normal)
    }
    
    // MARK: - Initialization
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupButton()
        setupActivityIndicator()
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        setupButton()
        setupActivityIndicator()
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        super.touchesBegan(touches, with: event)
        let feedbackGenerator = UIImpactFeedbackGenerator(style: .light)
        feedbackGenerator.prepare()
        feedbackGenerator.impactOccurred()
    }
    
    override var intrinsicContentSize: CGSize {
        let contentSize = super.intrinsicContentSize
        let height = CGFloat(44)
        return CGSize(width: contentSize.width, height: height)
    }

    
    // MARK: - Private methods
    
    private func setupButton() {
        setTitleColor(titleColor, for: .normal)
        backgroundColor = buttonBackgroundColor
        layer.cornerRadius = cornerRadius
        titleLabel?.font = font
        translatesAutoresizingMaskIntoConstraints = false
    }
    
    private func setupActivityIndicator() {
        activityIndicator = UIActivityIndicatorView(style: .medium)
        activityIndicator.hidesWhenStopped = true
        activityIndicator.color = UIColor.white
        activityIndicator.translatesAutoresizingMaskIntoConstraints = false
        addSubview(activityIndicator)
        
        NSLayoutConstraint.activate([
            activityIndicator.centerXAnchor.constraint(equalTo: centerXAnchor),
            activityIndicator.centerYAnchor.constraint(equalTo: centerYAnchor)
        ])
    }
    
    func showLoading() {
        originalButtonTitle = titleLabel?.text
        setTitle("", for: .normal)
        isEnabled = false
        activityIndicator.startAnimating()
    }
        
    func hideLoading() {
        setTitle(originalButtonTitle, for: .normal)
        isEnabled = true
        activityIndicator.stopAnimating()
    }
    
}

