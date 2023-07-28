//
//  SIQCustomStackView.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit

class SIQCustomStackView: UIStackView {
    
    var stackSpacing: CGFloat = 12 {
        didSet {
            spacing = stackSpacing
        }
    }
    
    var stackAxis: NSLayoutConstraint.Axis = .horizontal {
        didSet {
            axis = stackAxis
        }
    }
    
    var stackDistribution: UIStackView.Distribution = .fillEqually {
        didSet {
            distribution = stackDistribution
        }
    }
    
    init() {
        super.init(frame: .zero)
        setupView()
    }
    
    required init(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setupView() {
        axis = stackAxis
        spacing = stackSpacing
        distribution = stackDistribution
        alignment = .center
        translatesAutoresizingMaskIntoConstraints = false
    }

}
