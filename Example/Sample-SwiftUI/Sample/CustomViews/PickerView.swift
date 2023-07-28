//
//  PickerView.swift
//  Sample
//
//  Created by Sivasankar on 26/07/23.
//

import SwiftUI

struct PickerView: View {
    @State var selection: Int = 0
    var title: String
    var items: [String]
    var onChange:(_ selection:Int) -> Void
    var body: some View {
        HStack {
            Text(title)
            Spacer()
            Picker(title, selection: $selection) {
                ForEach(Array(items.enumerated()), id: \.element) { index, item in
                    Text(item).tag(index)
                }
            }.onChange(of: selection, perform: { newValue in
                onChange(newValue)
            })
            .pickerStyle(.segmented)
            .frame(width: 180)
        }
    }
}
