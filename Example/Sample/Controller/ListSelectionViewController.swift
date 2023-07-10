//
//  ListSelectionViewController.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 20/05/23.
//

import UIKit

class ListSelectionViewController: UIAlertController {
    
    private var items: [String] = []
    private var alertTitle: String?
    var willDismiss: ((String?) -> Void)?
    
    init(items: [String], title: String? = nil) {
        self.items = items
        self.alertTitle = title
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setTitle()
        setupList()
    }
    
    private func setTitle() {
        self.title = alertTitle
    }
    
    private func setupList() {
        for content in items {
            let action = UIAlertAction(title: content, style: .default, handler: { action in
                self.willDismiss?(action.title)
            })
            self.addAction(action)
        }
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel) { _ in }
        self.addAction(cancelAction)
    }
}
