#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include <string>
#include <rapidjson/document.h>

#define READ_DATA(value, data) Json::Read(value, #data, data)
#define READ_DATA_REQUIRED(value, data) Json::Read(value, #data, data, true)
#define HAS_DATA(value, data)value.HasMember(#data)
#define GET_DATA(value, data)value[#data]

namespace Json
{
	bool Load(const std::string& filename, rapidjson::Document& document);

	bool Read(const rapidjson::Value& value, const std::string& name, int& data, bool isReqiured = false);
	bool Read(const rapidjson::Value& value, const std::string& name, float& data, bool isReqiured = false);
	bool Read(const rapidjson::Value& value, const std::string& name, bool& data, bool isReqiured = false);
	bool Read(const rapidjson::Value& value, const std::string& name, std::string& data, bool isReqiured = false);
	bool Read(const rapidjson::Value& value, const std::string& name, Vector2& data, bool isReqiured = false);
	bool Read(const rapidjson::Value& value, const std::string& name, Color& data, bool isReqiured = false);
}

using json_t = rapidjson::Value;