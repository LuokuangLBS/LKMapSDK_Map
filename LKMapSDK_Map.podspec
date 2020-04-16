#
# Be sure to run `pod lib lint LKMapSDK_Map.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LKMapSDK_Map'
  s.version          = '2.0.0'
  s.summary          = '箩筐地图iOS SDK（CocoaPods箩筐地图官方库），地图功能包'

  s.description      = <<-DESC
箩筐地图iOS SDK（CocoaPods箩筐地图官方库），地图功能包。提供地图操作、标注、覆盖物绘制等功能。
                       DESC

  s.homepage         = 'https://lbs.luokuang.com'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'LuokuangLBS' => 'haofp@luokung.com' }
  s.source           = { :git => 'https://github.com/LuokuangLBS/LKMapSDK_Map.git', :tag => s.version.to_s }
  s.ios.deployment_target = '9.0'
  s.requires_arc = true
  s.resources =  'LKMapSDK_Map/LKMapSDK_Map.framework/LKMapSDK_Map.bundle'
  s.frameworks = 'UIKit', 'CoreGraphics', 'CoreLocation', 'CoreTelephony', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'Security', 'SystemConfiguration', 'GLKit'
  s.vendored_frameworks = 'LKMapSDK_Map/*.{framework}'
  s.libraries = 'c++', 'sqlite3', 'z'
  s.dependency 'LKMapSDK_Base', s.version.to_s
end
