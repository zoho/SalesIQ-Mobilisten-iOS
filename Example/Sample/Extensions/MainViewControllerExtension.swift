//
//  MainViewControllerExtension.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 07/06/23.
//

import UIKit

extension MainViewController {
    
    func setupView() {
        self.navigationItem.title = "Zoho SalesIQ Mobilisten"
        let separatorLineViewOne = separatorLineView
        let separatorLineViewTwo = separatorLineView
        let separatorLineViewThree = separatorLineView
        
        view.addSubview(scrollView)
        scrollView.addSubview(contentView)
        contentView.addSubview(siqLogoImageView)
        contentView.addSubview(openSupportButton)
        contentView.addSubview(LauncherVisibilityToggleView)
        contentView.addSubview(agentOnImageLauncherToggleView)
        contentView.addSubview(separatorLineViewOne)
        contentView.addSubview(visitorIDTextField)
        contentView.addSubview(sessionHorizontalStackView)
        sessionHorizontalStackView.addArrangedSubview(loginButton)
        sessionHorizontalStackView.addArrangedSubview(logoutButton)
        contentView.addSubview(separatorLineViewTwo)
        contentView.addSubview(setVisitorDetailButton)
        contentView.addSubview(supportLanguageToggleView)
        contentView.addSubview(separatorLineViewThree)
        contentView.addSubview(trackVisitorActivityButton)
        contentView.addSubview(fetchSalesIQDataButton)
        
        NSLayoutConstraint.activate([
            scrollView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.bottomAnchor),
            scrollView.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            scrollView.widthAnchor.constraint(equalTo: view.widthAnchor),
            
            contentView.topAnchor.constraint(equalTo: scrollView.topAnchor),
            contentView.bottomAnchor.constraint(equalTo: scrollView.bottomAnchor),
            contentView.centerXAnchor.constraint(equalTo: scrollView.centerXAnchor),
            contentView.widthAnchor.constraint(equalTo: scrollView.widthAnchor),
            
            siqLogoImageView.topAnchor.constraint(equalTo: contentView.topAnchor,constant: siqLogoTopPadding),
            siqLogoImageView.centerXAnchor.constraint(equalTo: contentView.centerXAnchor),
            siqLogoImageView.widthAnchor.constraint(equalToConstant: siqLogoSize.width),
            siqLogoImageView.heightAnchor.constraint(equalToConstant: siqLogoSize.height),
            
            openSupportButton.topAnchor.constraint(equalTo: siqLogoImageView.bottomAnchor,constant: openSupportButtonTopPadding),
            openSupportButton.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            openSupportButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            LauncherVisibilityToggleView.topAnchor.constraint(equalTo: openSupportButton.bottomAnchor,constant: LauncherVisibilityToggleViewTopPadding),
            LauncherVisibilityToggleView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            LauncherVisibilityToggleView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            agentOnImageLauncherToggleView.topAnchor.constraint(equalTo: LauncherVisibilityToggleView.bottomAnchor,constant: agentOnImageLauncherToggleViewTopPadding),
            agentOnImageLauncherToggleView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            agentOnImageLauncherToggleView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            separatorLineViewOne.topAnchor.constraint(equalTo: agentOnImageLauncherToggleView.bottomAnchor,constant: separatorLineViewTopPadding),
            separatorLineViewOne.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            separatorLineViewOne.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            separatorLineViewOne.heightAnchor.constraint(equalToConstant: separatorLineViewHeight),
            
            visitorIDTextField.topAnchor.constraint(equalTo: separatorLineViewOne.bottomAnchor,constant: visitorIDTextFieldTopPadding),
            visitorIDTextField.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            visitorIDTextField.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            sessionHorizontalStackView.topAnchor.constraint(equalTo: visitorIDTextField.bottomAnchor,constant: sessionHorizontalStackViewTopPadding),
            sessionHorizontalStackView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            sessionHorizontalStackView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            sessionHorizontalStackView.heightAnchor.constraint(equalToConstant: sessionHorizontalStackViewHeight),
            
            separatorLineViewTwo.topAnchor.constraint(equalTo: sessionHorizontalStackView.bottomAnchor,constant: separatorLineViewTopPadding),
            separatorLineViewTwo.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            separatorLineViewTwo.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            separatorLineViewTwo.heightAnchor.constraint(equalToConstant: separatorLineViewHeight),
            
            setVisitorDetailButton.topAnchor.constraint(equalTo: separatorLineViewTwo.bottomAnchor,constant: setVisitorDetailButtonTopPadding),
            setVisitorDetailButton.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            setVisitorDetailButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            supportLanguageToggleView.topAnchor.constraint(equalTo: setVisitorDetailButton.bottomAnchor,constant: supportLanguageToggleViewTopPadding),
            supportLanguageToggleView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            supportLanguageToggleView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            separatorLineViewThree.topAnchor.constraint(equalTo: supportLanguageToggleView.bottomAnchor,constant: separatorLineViewTopPadding),
            separatorLineViewThree.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            separatorLineViewThree.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            separatorLineViewThree.heightAnchor.constraint(equalToConstant: separatorLineViewHeight),
            
            trackVisitorActivityButton.topAnchor.constraint(equalTo: separatorLineViewThree.bottomAnchor,constant: trackVisitorActivityButtonTopPadding),
            trackVisitorActivityButton.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            trackVisitorActivityButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            fetchSalesIQDataButton.topAnchor.constraint(equalTo: trackVisitorActivityButton.bottomAnchor,constant: fetchSalesIQDataButtonTopPadding),
            fetchSalesIQDataButton.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            fetchSalesIQDataButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            fetchSalesIQDataButton.bottomAnchor.constraint(lessThanOrEqualTo: contentView.bottomAnchor)
            
        ])
        
    }
    
    func addTarget() {
        openSupportButton.addTarget(self, action: #selector(openSupportAction), for: .touchUpInside)
        LauncherVisibilityToggleView.segmentedControl.addTarget(self, action: #selector(showLauncherAction(_:)), for: .valueChanged)
        agentOnImageLauncherToggleView.segmentedControl.addTarget(self, action: #selector(showagentImageOnLauncherAction(_:)), for: .valueChanged)
        supportLanguageToggleView.segmentedControl.addTarget(self, action: #selector(supportLanguageAction(_:)), for: .valueChanged)
        loginButton.addTarget(self, action: #selector(registerVisitorAction), for: .touchUpInside)
        logoutButton.addTarget(self, action: #selector(UnregisterVisitorAction), for: .touchUpInside)
        setVisitorDetailButton.addTarget(self, action: #selector(setVisitorDetails), for: .touchUpInside)
        fetchSalesIQDataButton.addTarget(self, action: #selector(fetchData), for: .touchUpInside)
        trackVisitorActivityButton.addTarget(self, action: #selector(customAction), for: .touchUpInside)
    }
}
