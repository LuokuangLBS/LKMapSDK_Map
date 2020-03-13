#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKAnnotation.h"

NS_ASSUME_NONNULL_BEGIN


LK_EXPORT
/// 定位信息类。输出LKCoorTypeGCJ02坐标类型
@interface LKUserLocation : NSObject <LKAnnotation, NSSecureCoding>

/// 位置信息。未定位成功时，该属性为nil
@property (nonatomic, readonly, nullable) CLLocation *location;

/// 是否正在更新位置
@property (nonatomic, readonly, getter=isUpdating) BOOL updating;

/// 朝向。如果跟踪模式不是LKUserTrackingModeFollowWithHeading或LKMapView.showsUserHeadingIndicator被禁止时，该属性为nil
@property (nonatomic, readonly, nullable) CLHeading *heading;


/// 标题
@property (nonatomic, copy) NSString *title;

/// 副标题
@property (nonatomic, copy, nullable) NSString *subtitle;

@end

NS_ASSUME_NONNULL_END
