Pod::Spec.new do |s|
  s.name         =  'OpenXMSDK'
  s.version      =  '1.4.1'
  s.platform	 =  :ios, '5.1'
  s.summary		 =  'OpenX Ad Server Mobile SDK'
  s.description  =  'The OpenX SDK for iOS allows users of the OpenX Ad Server to incorporate ads into their iOS applications.'
  s.homepage     =  'http://www.openx.com'
  s.author       =  { 'Lawrence Leach' => 'lawrence.leach@openx.com' }
  s.requires_arc = false
  s.license      =  {
  	:type	=> 'Commercial',
    :text => 'Copyright 2013 OpenX Technologies, Inc. All rights reserved.'
  }
  s.source = { 
  	:git => 'https://github.com/lawrenceleach/OpenXMSDK-CocoaPod.git', 
    :tag => s.version.to_s
  }
  s.source_files = 'Headers/*.{h,m}'
  s.library = "OpenXMSDK"
  s.resource_bundles = { 'OpenXMSDK' => "OpenXMSDK.bundle" }
  s.frameworks 	 = 'SystemConfiguration', 'AdSupport', 'CoreGraphics', 'CoreLocation', 'CoreTelephony', 'EventKit', 'EventKitUI', 'MapKit', 'MediaPlayer'
end
