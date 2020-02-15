#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKAnnotation.h"
#import <LKMapSDK_Base/LKCoordUtil.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 覆盖物协议
 */
@protocol LKOverlay <LKAnnotation>

/// 地理坐标
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/// 矩形地理区域
@property (nonatomic, readonly) LKCoordinateBounds overlayBounds;

/**
 * 是否与指定矩形区域相交
 *
 * @param overlayBounds 矩形区域
 * @return 是否相交
 */
- (BOOL)intersectsOverlayBounds:(LKCoordinateBounds)overlayBounds;

@end

NS_ASSUME_NONNULL_END
