//
//  SIQSupportLanguageView.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit
import Mobilisten

class SIQSupportLanguageView: UIView {
    
    let titleLabel: UILabel = {
        let label = UILabel()
        label.text = "Support language:"
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    let horizontalStackView: SIQCustomStackView = {
        let stackView = SIQCustomStackView()
        stackView.stackSpacing = 20
        return stackView
    }()
    
    let englishButton: SIQCustomButton = {
      let button = SIQCustomButton(title: "EN")
        button.buttonBackgroundColor = .clear
        button.titleColor = .systemBlue
        return button
    }()
    
    let frenchButton: SIQCustomButton = {
      let button = SIQCustomButton(title: "FR")
        button.buttonBackgroundColor = .clear
        button.titleColor = .systemBlue
        return button
    }()
    
    let japaneseButton: SIQCustomButton = {
      let button = SIQCustomButton(title: "JA")
        button.buttonBackgroundColor = .clear
        button.titleColor = .systemBlue
        return button
    }()
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupView()
        addTarget()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setupView() {
        addSubview(titleLabel)
        addSubview(horizontalStackView)
        
        horizontalStackView.addArrangedSubview(englishButton)
        horizontalStackView.addArrangedSubview(frenchButton)
        horizontalStackView.addArrangedSubview(japaneseButton)
        
        NSLayoutConstraint.activate([
            horizontalStackView.topAnchor.constraint(equalTo: topAnchor),
            horizontalStackView.trailingAnchor.constraint(equalTo: trailingAnchor),
            horizontalStackView.bottomAnchor.constraint(equalTo: bottomAnchor),
            
            titleLabel.topAnchor.constraint(equalTo: topAnchor),
            titleLabel.leadingAnchor.constraint(equalTo: leadingAnchor),
            titleLabel.bottomAnchor.constraint(equalTo: bottomAnchor),
            titleLabel.trailingAnchor.constraint(lessThanOrEqualTo: horizontalStackView.leadingAnchor,constant: 10),
        ])
    }
    
    private func addTarget() {
        englishButton.addTarget(self, action: #selector(englishButtonAction), for: .touchUpInside)
        frenchButton.addTarget(self, action: #selector(frenchButtonAction), for: .touchUpInside)
        japaneseButton.addTarget(self, action: #selector(japaneseButtonAction), for: .touchUpInside)
    }
    
    /**
     This API lets you configure the language preference for the embedded chat widget.
     
     [.Chat.setLanguage()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-language-v3.html)
     */
    @objc func englishButtonAction() {
        ZohoSalesIQ.Chat.setLanguage(.english)
    }
    
    @objc func frenchButtonAction() {
        ZohoSalesIQ.Chat.setLanguage(.french)
    }
    
    @objc func japaneseButtonAction() {
        ZohoSalesIQ.Chat.setLanguage(.japanese)
    }
    
}
