#import <Foundation/Foundation.h>

#import "LKFoundation.h"
#import "LKAnnotation.h"

NS_ASSUME_NONNULL_BEGIN


LK_EXPORT
/// 抽象类。定义了遵守LKAnnotation协议的LKShape类的基本属性和行为，请使用它的必须子类
@interface LKShape : NSObject <LKAnnotation, NSSecureCoding>

/// 标题
@property (nonatomic, copy, nullable) NSString *title;

/// 副标题
@property (nonatomic, copy, nullable) NSString *subtitle;
@end

NS_ASSUME_NONNULL_END
