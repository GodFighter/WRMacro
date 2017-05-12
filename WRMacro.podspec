Pod::Spec.new do |s|
  s.name         = "WRMacro"
  s.version      = "1.0.0"
  s.summary      = "宏定义."
  s.description  = "个人常用宏定义."
  s.homepage     = "https://github.com/GodFighter/WRMacro.git"
  s.license      = "MIT"
  s.author       = { "Leo Xiang" => "xianghui_ios@163.com" }
  s.source       = { :git => "https://github.com/GodFighter/WRMacro.git", :tag => s.version }
  s.source_files = 'WRMacro/*.{h,m}'
  s.ios.deployment_target = '7.0'
  s.frameworks   = 'UIKit'
  s.social_media_url = "http://weibo.com/huigedang/home?wvr=5&lf=reg"
  s.requires_arc = true

end
