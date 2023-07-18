Pod::Spec.new do |spec|
spec.name             = "Mobilisten"
spec.version          = "5.4.1"
spec.summary          = "Mobilisten iOS SDK"
spec.license          = { :type => "MIT", :text=> <<-LICENSE
MIT License
Copyright (c) 2021 Zoho Corporation
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE
LICENSE
}

spec.homepage         = "https://zoho.com"
spec.author           = { "Rishabh" => "rishabh.r@zohocorp.com" }
spec.source = { :http => "https://raw.githubusercontent.com/zoho/SalesIQ-Mobilisten-iOS/v#{spec.version}/Mobilisten.zip" }
spec.source_files = 'Mobilisten.xcframework/*/Mobilisten.framework/Headers/*.{h,m,swift}'
spec.ios.vendored_frameworks = 'Mobilisten.xcframework'
spec.social_media_url = "http://zoho.com"
spec.ios.deployment_target = '11.0'
spec.requires_arc = true
end
