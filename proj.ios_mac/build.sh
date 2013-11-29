#!/bin/sh
xcodebuild -target "SpriteBuilder Mac" -configuration Debug
xcodebuild -target "SpriteBuilder Mac" -configuration Release
xcodebuild -target "SpriteBuilder iOS" -configuration Debug -sdk iphoneos7.0
xcodebuild -target "SpriteBuilder iOS" -configuration Release -sdk iphoneos7.0
xcodebuild -target "SpriteBuilder iOS" -configuration Debug -sdk iphonesimulator7.0
xcodebuild -target "SpriteBuilder iOS" -configuration Release -sdk iphonesimulator7.0
