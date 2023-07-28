//
//  ContentView.swift
//  Sample
//
//  Created by Sivasankar on 25/07/23.
//

import SwiftUI

struct ContentView: View {
    let vStackPadding = UIEdgeInsets(top: 0, left: 12, bottom: 0, right: 12)
    let buttonSize = CGSize(width: 0, height: 40)
    let siqLogoSize: CGSize = CGSize(width: 100, height: 100)
    let commonPadding = UIEdgeInsets(top: 12, left: 0, bottom: 0, right: 0)
    
    @State var visitorIdInput: String = ""
    @State var showFeedbackError: Bool = false
    @State var isShowingNextView = false
    @State var showLauncher:Bool = true
    
    var body: some View {
        GeometryReader { geometry in
            NavigationStack {
                ScrollView {
                    VStack(alignment: .center) {
                        Text("Zoho SalesIQ Mobilisten")
                            .padding(.leading)
                        Image("salesiq_logo")
                            .resizable()
                            .frame(width: siqLogoSize.width, height: siqLogoSize.height)
                        SIQCustomButton(name: "Open SalesIQ support", textSize: CGSize(width: geometry.size.width-(vStackPadding.left+vStackPadding.right), height: buttonSize.height)) { completion in
                            MobilistenImplementation.openSalesIQChat()
                            completion()
                        }
                        Divider()
                            .padding(.top,commonPadding.top)
                        Group {
                            PickerView(selection: 1, title: "Launcher visibility:", items: ["Hide","Show"]) { selection in
                                showLauncher = selection == 1 ? true : false
                                MobilistenImplementation.showLauncher(showLauncher)
                            }
                            .padding(.top,commonPadding.top)
                            PickerView(title: "Operator image on Launcher:", items: ["Hide","Show"]) { selection in
                                let status = selection == 1 ? true : false
                                MobilistenImplementation.setAttenderImageVisibility(status)
                            }
                            PickerView(title: "Support language:", items: ["EN","FR","JA"]) { selection in
                                MobilistenImplementation.setLanguage(selection)
                            }
                            Divider().padding(.top,commonPadding.top)
                        }
                        Group {
                            TextField("Enter visitor ID", text: $visitorIdInput)
                                .textFieldStyle(RoundedBorderTextFieldStyle())
                                .shakeFeedback(shake: $showFeedbackError)
                                .padding(.top,commonPadding.top)
                            HStack {
                                SIQCustomButton(name: "Login", textSize: CGSize(width: geometry.size.width/2-(vStackPadding.left+vStackPadding.right), height: buttonSize.height)) { completion in
                                    if visitorIdInput.isEmpty == true {
                                        showFeedbackError = true
                                        completion()
                                        return
                                    } else {
                                        showFeedbackError = false
                                    }
                                    MobilistenImplementation.register(uniqueID: visitorIdInput) {
                                        completion()
                                    }
                                    
                                }
                                SIQCustomButton(name: "Logout", textSize: CGSize(width: geometry.size.width/2-(vStackPadding.left+vStackPadding.right), height: buttonSize.height)) { completion in
                                    MobilistenImplementation.unRegister {
                                        completion()
                                    }
                                }
                                
                            }
                            Divider()
                                .padding(.top,commonPadding.top)
                        }
                        Group {
                            SIQCustomButton(name: "Proactive custom action trigger", textSize: CGSize(width: geometry.size.width-(vStackPadding.left+vStackPadding.right), height: buttonSize.height)) { completion in
                                MobilistenImplementation.setCustomAction(name: "Zylkar")
                                completion()
                            }
                            .padding(.top,commonPadding.top)
                            NavigationLink(destination: VisitorDetailView()) {
                                SIQCustomButton(name: "Update visitor info & Start chat", textSize: CGSize(width: geometry.size.width-(vStackPadding.left+vStackPadding.right), height: buttonSize.height)) { completion in
                                    isShowingNextView = true
                                    completion()
                                } .navigationDestination(isPresented: $isShowingNextView) {
                                    VisitorDetailView()
                                }
                                
                            }
                        }
                    }
                    .padding(.leading,vStackPadding.left)
                    .padding(.trailing,vStackPadding.right)
                }
                .onAppear {
                    if showLauncher == true {
                        MobilistenImplementation.showLauncher(showLauncher)
                    }
                }
                .onDisappear {
                    if showLauncher == true {
                        MobilistenImplementation.showLauncher(false)
                    }
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
