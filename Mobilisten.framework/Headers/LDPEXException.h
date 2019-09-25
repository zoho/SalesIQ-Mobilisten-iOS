//
//  PEXException.h
//  LDPEXLibrary
//
//  Created by Balaji Sankar on 25/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 PEX exceptions are raised when there is an error in processing PEXRequests
 @discussion The methods which invoke LDPEXLibrary::process: should handle this exception
 @see LDPEXLibrary
 */
@interface PEXException : NSException
{
    int code;
    NSString *msg;
}
/**
 Denotes the error code
 */
@property int code;
/**
 Denotes the corresponding error message
 */
@property NSString *msg;
@end

