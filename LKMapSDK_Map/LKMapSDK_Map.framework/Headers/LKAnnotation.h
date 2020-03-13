#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <TargetConditionals.h>

NS_ASSUME_NONNULL_BEGIN

/// 标注协议
@protocol LKAnnotation <NSObject>

/// 标注中心地理坐标
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

@optional

/// 标题
@property (nonatomic, readonly, copy, nullable) NSString *title;

/// 副标题
@property (nonatomic, readonly, copy, nullable) NSString *subtitle;


#if !TARGET_OS_IPHONE

/// 提示
@property (nonatomic, readonly, copy, nullable) NSString *toolTip;

#endif

@end

NS_ASSUME_NONNULL_END
