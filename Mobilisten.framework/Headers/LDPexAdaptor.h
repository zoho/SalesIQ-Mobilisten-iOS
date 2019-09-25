//
//  LDPexAdaptor.h
//  LiveChat
//
//  Created by Shanmuga Sundaram G on 05/05/16.
//  Copyright © 2016 Zoho. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LDWMSPEXAdapter.h"


@interface LDPexAdaptor : WMSPEXAdapter
@property(nonatomic, strong)NSString* appKey;
@property(nonatomic, strong)NSString* agetnHeader;

@end
