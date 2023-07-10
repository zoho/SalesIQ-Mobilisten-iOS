//
//  DataPrintUtils.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 07/06/23.
//

import Foundation
import Mobilisten

class DataPrintUtils {
    static let shared = DataPrintUtils()

    func chatDetails(_ chat: SIQVisitorChat?) {
        guard let chat = chat else { return }
        print("-------------------------------------------")
        print("AttenderEmail :",chat.attenderEmail as Any)
        print("AttenderID :",chat.attenderID as Any)
        print("AttenderName :",chat.attenderName as Any)
        print("DepartmentName :",chat.departmentName as Any)
        print("Feedback :",chat.feedback as Any)
        print("IsBotAttender :",chat.isBotAttender)
        print("LastMessage.time :",chat.lastMessage.time as Any)
        print("LastMessage.sender :",chat.lastMessage.sender as Any)
        print("LastMessage.text :",chat.lastMessage.text as Any)
        print("LastMessage.isRead :",chat.lastMessage.isRead)
        print("LastMessage.isEdited :",chat.lastMessage.isEdited)
        print("LastMessage.isDeleted :",chat.lastMessage.isDeleted)
        print("LastMessage.file.name :",chat.lastMessage.file?.name as Any)
        print("LastMessage.file.size :",chat.lastMessage.file?.size as Any)
        print("LastMessage.file.contentType :",chat.lastMessage.file?.contentType as Any)
        print("LastMessage.file.comment :",chat.lastMessage.file?.comment as Any)
        print("Question :",chat.question as Any)
        print("Rating :",chat.rating as Any)
        print("ReferenceID :",chat.referenceID as Any)
        print("Status :",getChatStatus(chat.status.rawValue) as Any)
        print("UnreadCount :",chat.unreadCount)
        print("QueuePosition :",chat.queuePosition)
    }
    
    func articleDetails(_ article: SIQFAQArticle?) {
        guard let article = article else { return }
        print("-------------------------------------------")
        print("Id :",article.id)
        print("Name :",article.name)
        print("IsRated :",article.isRated)
        print("View count :",article.viewCount)
        print("Like count :",article.likeCount)
        print("Dislike count :",article.dislikeCount)
        print("Category name :",article.categoryName)
        print("Category id :",article.categoryID)
        print("Department id :",article.departmentID)
        print("Created Time :",article.createdTime as Any)
        print("Last Modified Time :",article.lastModifiedTime as Any)
    }
    
    
    func visitorDetails(_ detail: SIQVisitor?) {
        guard let detail = detail else { return }
        print("-------------------------------------------")
        print("Visitor name :",detail.name as Any)
        print("Visitor email :",detail.email as Any)
        print("Visitor phone :",detail.phone as Any)
        print("Visitor browser :",detail.browser as Any)
        print("Visitor ip :",detail.ip as Any)
        print("Visitor country code :",detail.countryCode as Any)
        print("Visitor search engine :",detail.searchEngine as Any)
        print("Visitor search query :",detail.searchQuery as Any)
        print("Visitor region :",detail.region as Any)
        print("Visitor state :",detail.state as Any)
        print("Visitor city :",detail.city as Any)
        print("Visitor numberOfChats :",detail.numberOfChats as Any)
        print("Visitor numberOfVisits :",detail.numberOfVisits as Any)
        print("Visitor noOfDaysVisited :",detail.noOfDaysVisited as Any)
        print("Visitor totalTimeSpent :",detail.totalTimeSpent as Any)
        print("Visitor firstVisitTime :",detail.firstVisitTime as Any)
        print("Visitor lastVisitTime :",detail.lastVisitTime as Any)
    }
    
    func getChatStatus(_ rawValue: Int) -> String? {
        switch ChatStatus(rawValue: rawValue) {
        case .open:
            return "open"
        case .triggered:
            return "triggered"
        case .proactive:
            return "proactive"
        case .connected:
            return "connected"
        case .waiting:
            return "waiting"
        case .missed:
            return "missed"
        case .closed:
            return "closed"
        case .ended:
            return "ended"
        case .all:
            return "all"
        default:
            return nil
        }
    }
}
