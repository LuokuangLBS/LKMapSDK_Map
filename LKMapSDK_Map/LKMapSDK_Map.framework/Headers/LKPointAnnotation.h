#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "LKFoundation.h"
#import "LKShape.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 点标注
 */
LK_EXPORT
@interface LKPointAnnotation : LKShape

/// 地理坐标
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

NS_ASSUME_NONNULL_END
