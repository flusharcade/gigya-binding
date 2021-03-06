#import <Foundation/Foundation.h>
#import "GSObject.h"

/** 
 This class represents a response from the <a target="_blank" href="http://developers.gigya.com/037_API_reference">Gigya REST API</a>.
 
 `GSResponse` values can be accessed by keys (similiar to NSDictionary) and support subscripting syntax:
    
    // These two statements are equivalent
    NSString *token = [response objectForKey:@"token"];
    NSString *token = response[@"token"];
 */
@interface GSResponse : GSObject

+ (GSResponse *)responseForMethod:(NSString *)method data:(NSData *)data;
+ (GSResponse *)responseWithError:(NSError *)error;

/** @name Basic Response Information */

/*!
 The API method name.
 */
@property (weak, readonly) NSString *method;

/*!
 The result code of the operation. Value of 0 indicates success, any other number indicates failure. For a complete list of error codes, see the <a target="_blank" href="http://developers.gigya.com/030_API_reference/030_Response_Codes_and_Errors">Error Codes table</a>.
 */
@property (readonly) int errorCode;

/*!
 Unique identifier of the transaction, for debugging purposes.
 */
@property (weak, readonly) NSString *callId;

/** @name Accessing Keys and Values */

/*!
 Returns an array containing the response dictionary keys.
 
 @returns An array containing the response keys.
 */
- (NSArray *)allKeys;

/*!
 Returns the value associated with the given key.
 
 @param key The key for which to return the value.
 */
- (id)objectForKey:(NSString *)key;

/*!
 Returns the value associated with the given key.
 
 This method is the same as <objectForKey:>, but is required for subscripting syntax.
 
 @param key The key for which to return the value.
 */
- (id)objectForKeyedSubscript:(NSString *)key;

/** @name JSON Encoding */

/*!
 Returns a JSON representation of the response.
 */
- (NSString *)JSONString;

@end
