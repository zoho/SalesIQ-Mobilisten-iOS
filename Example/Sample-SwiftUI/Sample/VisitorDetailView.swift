//
//  VisitorDetailView.swift
//  Sample
//
//  Created by Sivasankar on 26/07/23.
//

import SwiftUI
import Mobilisten
struct VisitorDetailView: View {
    let vStackPadding = UIEdgeInsets(top: 0, left: 12, bottom: 0, right: 12)
    let commonPadding = UIEdgeInsets(top: 12, left: 0, bottom: 0, right: 0)
    let textFiledPadding = UIEdgeInsets(top: 4, left: 0, bottom: 0, right: 0)
    let buttonSize = CGSize(width: 0, height: 40)
    @State var nameInput: String = ""
    @State var nameInputFeedbackError: Bool = false
    @State var emailInput: String = ""
    @State var emailInputFeedbackError: Bool = false
    @State var phoneInput: String = ""
    @State var phoneInputFeedbackError: Bool = false
    @State var questionInput: String = ""
    @State var questionInputFeedbackError: Bool = false
    @State var selectedDepartment:String = ""
    @State var departmentList:[String] = []
    @State var isPresented = false
    var body: some View {
        GeometryReader { geometry in
            NavigationView {
                ScrollView {
                    VStack {
                        Group {
                            Text("Visitor details")
                                .padding(.top,commonPadding.top)
                            TextField("Enter your(visitor) name", text: $nameInput)
                                .textFieldStyle(.roundedBorder)
                                .shakeFeedback(shake: $nameInputFeedbackError)
                                .padding(.top,textFiledPadding.top)
                            TextField("Enter your(visitor) email address", text: $emailInput)
                                .textFieldStyle(RoundedBorderTextFieldStyle())
                                .shakeFeedback(shake: $emailInputFeedbackError)
                                .padding(.top,textFiledPadding.top)
                            TextField("Enter your(visitor) contact number", text: $phoneInput)
                                .textFieldStyle(RoundedBorderTextFieldStyle())
                                .shakeFeedback(shake: $phoneInputFeedbackError)
                                .padding(.top,textFiledPadding.top)
                            SIQCustomButton(name: "Save visitor details", textSize: CGSize(width: geometry.size.width-(vStackPadding.left+vStackPadding.right), height: buttonSize.height), action: { completion in
                                if nameInput.isEmpty == false {
                                    MobilistenImplementation.setVisitorName(nameInput)
                                } else {
                                    nameInputFeedbackError = true
                                }
                                if emailInput.isEmpty == false {
                                    MobilistenImplementation.setVisitorEmail(emailInput)
                                } else {
                                    emailInputFeedbackError = true
                                }
                                if phoneInput.isEmpty == false {
                                    MobilistenImplementation.setVisitorContactNumber(phoneInput)
                                } else {
                                    phoneInputFeedbackError = true
                                }
                                completion()
                            })
                            .padding(.top,commonPadding.top)
                            Divider()
                                .padding(.top,commonPadding.top)
                        }
                        Group {
                            Text("Start chat")
                                .padding(.top,commonPadding.top)
                            TextField("Enter your(visitor) question here", text: $questionInput)
                                .textFieldStyle(RoundedBorderTextFieldStyle())
                                .shakeFeedback(shake: $questionInputFeedbackError)
                            SIQCustomButton(name: "Choose a department", textSize: CGSize(width: geometry.size.width-(vStackPadding.left+vStackPadding.right), height: buttonSize.height), action: { completion in
                                if departmentList.count == 0 {
                                    MobilistenImplementation.departmentlist { error, departments in
                                        if let departments {
                                            departmentList = departments.map({ department in
                                                return department.name
                                            })
                                            isPresented = true
                                            completion()
                                        }
                                        
                                    }
                                } else {
                                    isPresented = true
                                    completion()
                                }
                            })
                            .padding(.top,commonPadding.top)
                            .confirmationDialog("Choose a department", isPresented: $isPresented) {
                                ForEach(departmentList, id: \.self) { department in
                                    Button(action: {
                                        selectedDepartment = department
                                    }) {
                                        Text(department)
                                    }
                                }
                            }
                            if selectedDepartment.isEmpty == false {
                                HStack {
                                    Text("Selected department:")
                                    Text(selectedDepartment).foregroundColor(.blue)
                                }
                            }
                            SIQCustomButton(name: "Custom UI Start Chat ", textSize: CGSize(width: geometry.size.width-(vStackPadding.left+vStackPadding.right), height: buttonSize.height)) { completion in
                                if questionInput.isEmpty == false {
                                    MobilistenImplementation.startChat(questionInput)
                                } else {
                                    questionInputFeedbackError = true
                                }
                                completion()
                            }
                        }
                    }
                }.padding(.leading,vStackPadding.left)
                    .padding(.trailing,vStackPadding.right)
            }
            .navigationTitle("Update visitor info & Start chat")
        }
    }
}

struct VisitorDetailView_Previews: PreviewProvider {
    static var previews: some View {
        VisitorDetailView()
    }
}
