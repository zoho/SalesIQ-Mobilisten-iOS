//
//  SIQToggleView.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit
import Mobilisten

class SIQToggleView: UIView {
    
    let segmentedControl: UISegmentedControl = {
        let toggle = UISegmentedControl(items: [])
        toggle.selectedSegmentIndex = 0
        toggle.backgroundColor = .clear
        toggle.layer.borderColor = UIColor.systemBlue.cgColor
        toggle.layer.cornerRadius = 5
        toggle.selectedSegmentTintColor = .systemBlue
        toggle.layer.borderWidth = 1
        toggle.setTitleTextAttributes([.foregroundColor: UIColor(named: "inverse")], for: .normal)
        toggle.setTitleTextAttributes([.foregroundColor: UIColor.white], for: .selected)
        return toggle
    }()
    
    private let horizontalStackView : SIQCustomStackView = {
        let stackView = SIQCustomStackView()
        stackView.stackDistribution = .fillProportionally
        return stackView
    }()
    
    private let titleLabel: UILabel = {
      let label = UILabel()
        label.numberOfLines = 0
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    private let segmentedControlSize: CGSize = CGSize(width: 120, height: 40)
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupView()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    private func setupView() {
        addSubview(horizontalStackView)
        horizontalStackView.addArrangedSubview(titleLabel)
        horizontalStackView.addArrangedSubview(segmentedControl)
        NSLayoutConstraint.activate([
            horizontalStackView.topAnchor.constraint(equalTo: topAnchor),
            horizontalStackView.leadingAnchor.constraint(equalTo: leadingAnchor),
            horizontalStackView.trailingAnchor.constraint(equalTo: trailingAnchor),
            horizontalStackView.bottomAnchor.constraint(equalTo: bottomAnchor),
            
            segmentedControl.widthAnchor.constraint(equalToConstant: segmentedControlSize.width),
            segmentedControl.heightAnchor.constraint(equalToConstant: segmentedControlSize.height)
        ])
    }
    
    func setup(type: SIQToggle) {
        configureSegmentedControl(type)
        self.titleLabel.text = type.title
    }
    
    func configureSegmentedControl(_ type: SIQToggle) {
        let items = type.items
        let selectedIndex = 0
        segmentedControl.removeAllSegments()
        for (index, item) in items.enumerated() {
            segmentedControl.insertSegment(withTitle: item, at: index, animated: false)
        }
        segmentedControl.selectedSegmentIndex = selectedIndex
    }

}
