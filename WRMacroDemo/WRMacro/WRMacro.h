//
//  WRMacro.h
//  WRMacro
//
//  Created by xianghui on 2017/5/10.
//  Copyright © 2017年 xianghui. All rights reserved.
//

#ifndef WRMacro_h
#define WRMacro_h

#pragma mark -
#pragma mark Common
/**
 * Device Size, the value of this property may change when the device rotates between portrait and landscape orientations
 */
#define WR_SCREEN_SIZE              ([UIScreen mainScreen].bounds.size)
/**
 * Device Native Size, This value does not change as the device rotates
 */
#define WR_NATIVE_SCREEN_SIZE       ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width / [UIScreen mainScreen].nativeScale, [UIScreen mainScreen].nativeBounds.size.height / [UIScreen mainScreen].nativeScale) : CGSizeMake(WR_SCREEN_MIN_LENGTH, WR_SCREEN_MAX_LENGTH))
/**
 * weak self
 */
#define WR_WEAKSELF                 __weak typeof(self)wr_weakSelf = self;
/**
 * strong self
 */
#define WR_STRONGSELF               __strong typeof(wr_weakSelf)wr_strongSelf = wr_weakSelf;
/**
 * weak object
 */
#define WR_WEAKOBJECT(a)            __weak typeof(a) wr_weakObject_##a = a;
/**
 * strong object
 */
#define WR_STRONGOBJECT(a)          __strong typeof(a) wr_strongObject_##a = a;
/**
 * device max length, vertical screen is high,landscape is width
 */
#define WR_SCREEN_MAX_LENGTH       (MAX(WR_SCREEN_SIZE.width, WR_SCREEN_SIZE.height))
/**
 * device min length, vertical screen is width,landscape is high
 */
#define WR_SCREEN_MIN_LENGTH       (MIN(WR_SCREEN_SIZE.width, WR_SCREEN_SIZE.height))

#pragma mark -
#pragma mark Device
/**
 * ipad
 */
#define WR_IS_IPAD                 (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
/**
 * iphone
 */
#define WR_IS_IPHONE               (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
/**
 * iphone4s,iphone4,iphone3GS
 */
#define WR_IS_IPHONE_4S_OR_LESS     (WR_IS_IPHONE && WR_SCREEN_MAX_LENGTH < 568.0)
/**
 * iphone5s,iphone5,iphoneSE
 */
#define WR_IS_IPHONE_5_5S_SE        (WR_IS_IPHONE && WR_SCREEN_MAX_LENGTH == 568.0)
/**
 * iphone6,iphone7
 */
#define WR_IS_IPHONE_6_OR_7         (WR_IS_IPHONE && WR_SCREEN_MAX_LENGTH == 667.0)
/**
 * iphone6P,iphone7P
 */
#define WR_IS_IPHONE_6P_OR_7P       (WR_IS_IPHONE && WR_SCREEN_MAX_LENGTH == 736.0)
/**
 * current system version digital(float)
 */
#define WR_SYSTEM_VERSION_DIGITAL   [[UIDevice currentDevice].systemVersion floatValue]
/**
 * current system version string
 */
#define WR_SYSTEM_VERSION_STRING    [UIDevice currentDevice].systemVersion
/**
 * Greater or equal
 */
#define WR_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)      ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
/**
 * Greater
 */
#define WR_SYSTEM_VERSION_GREATER_THAN(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
/**
 * less or equal
 */
#define WR_SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)         ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
/**
 * less
 */
#define WR_SYSTEM_VERSION_LESS_THAN(v)                     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
/**
 * equal
 */
#define WR_SYSTEM_VERSION_EQUAL(v)                         ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define WR_IOS_8                    (WR_SYSTEM_VERSION_DIGITAL >= 8.0 && WR_SYSTEM_VERSION_DIGITAL <= 9.0)
#define WR_IOS_9                    (WR_SYSTEM_VERSION_DIGITAL >= 9.0 && WR_SYSTEM_VERSION_DIGITAL <= 10.0)
#define WR_IOS_10_OR_LATER          WR_SYSTEM_VERSION_DIGITAL >= 10.0
#pragma mark -
#pragma mark GCD
/**
 * GCD async main thread
 */
#define WR_DISPATCH_MAIN_THREAD(mainQueueBlock)             dispatch_async(dispatch_get_main_queue(), mainQueueBlock);
/**
 * GCD async global thread
 */
#define WR_DISPATCH_GLOBAL_THREAD(globalQueueBlock)  dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlock);
#pragma mark -
#pragma mark Color
/**
 * color whith RGB
 */
#define WR_COLOR_RGB(r, g, b)           [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
/**
 * color whith RGBA
 */
#define WR_COLOR_RGBA(r, g, b, a)       [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
/**
 * color whith HEX
 */
#define WR_COLOR_HEX(rgbValue)          [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
/**
 * clear color
 */
#define WR_COLOR_CLEAR                 [UIColor clearColor]
/**
 * random color
 */
#define WR_COLOR_RANDOM                WR_COLOR_RGB(arc4random_uniform(256)/255.0, arc4random_uniform(256)/255.0, arc4random_uniform(256)/255.0)
#pragma mark -
#pragma mark Path
/**
 * app home path
 */
#define WR_PATH_HOMEAPP                    NSHomeDirectory()
/**
 * app Documents path
 */
#define WR_PATH_DOCUMENTS                  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
/**
 * app Caches path
 */
#define WR_PATH_CACHES                     [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
/**
 * app tmp path
 */
#define WR_PATH_TMP                        NSTemporaryDirectory()
/**
 * app file in bundle path
 */
#define WR_PATH_BUNDLE(name, type)         [[NSBundle mainBundle] pathForResource:name ofType:type]
#pragma mark -
#pragma mark Log
/**
 * Normal log
 */
#ifdef DEBUG
    #define WR_Log(...) NSLog(__VA_ARGS__)
#else
    #define WR_Log(...)
#endif
/**
 * log add method
 */
#define WR_LOG_WITH_METHOD(...)          WR_Log(@"%s\n%@",__FUNCTION__, __VA_ARGS__);
/**
 * log add line
 */
#define WR_LOG_WITH_LINE(...)            WR_Log(@"%d\n%@",__LINE__, __VA_ARGS__);
/**
 * log add class
 */
#define WR_LOG_WITH_CLASS(...)           WR_Log(@"%s\n%@",__FILE__, __VA_ARGS__);
/**
 * log add stack
 */
#define WR_LOG_WITH_STACK(...)           WR_Log(@"%@\n%@",[NSThread callStackSymbols], __VA_ARGS__);
/**
 * log add path
 */
#define WR_LOG_WITH_PATH(...)            WR_Log(@"%s\n%@",__FILE__, __VA_ARGS__);
/**
 * log add class, method, line 
 */
#define WR_LOG_WITH_DETAIL(...)          WR_Log(@"class==>%@, method==>%s, line==>%d\n%@",[self class],__FUNCTION__,__LINE__, __VA_ARGS__);

#pragma mark -
#pragma mark Language
/**
 * current language
 */
#define WR_CURRENT_LANGUAGE                 ([[NSLocale preferredLanguages] objectAtIndex:0])
/**
 * Singleton
 */
#define WR_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [[self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}

#endif /* WRMacro_h */
