#pragma once
#include <Windows.h>

#include "External/AddressRule.h"

/*
* Represents an XXFile with values specific to faces. Can be safely casted to XXFile.
*/
class XXFileFace
{
public:
	XXFileFace();
	~XXFileFace();

	inline float* GetBlush() {
		const static DWORD rule[]{ 0x234, 0x44 * 0x8 + 0x0C, 0x194, 0x50, 0x14 };
		return (float*)ExtVars::ApplyRule(this, rule);
	}
	
	inline float* GetBlushLines() {
		const static DWORD rule[]{ 0x234, 0x44 * 0x8 + 0x0C, 0x194, 0x50, 0x148 };
		return (float*)ExtVars::ApplyRule(this, rule);
	}

	BYTE m_unknown1[0x224];
	void* m_morphsPointer1;
	DWORD m_morphsUnknown1;
	void* m_morphShapesPointer;
	DWORD m_morphsUnknown2;
	void* m_morphsPointer3;
	BYTE m_unknown2[0x4];
	// mouth shape
	int m_mouth;
	BYTE m_unknown3[0x18];
	// eye shape
	int m_eye;
	BYTE m_unknown4[0x18];
	// eyebrow shape
	int m_eyebrow;
	BYTE m_unknown5[0x30];
	// max eye open status
	float m_eyeOpen;
	BYTE m_unknown6[0x8];
	// min mouth open status
	float m_mouthOpen;
	BYTE m_unknown7[0x1C768];
	// lock eye tracking
	bool m_eyeTracking;

	static inline void bindLua() {
#define LUA_CLASS XXFileFace
		LUA_NAME;
		LUA_BIND(m_mouth);
		LUA_BIND(m_eye);
		LUA_BIND(m_eyebrow);
		LUA_BIND(m_eyeOpen);
		LUA_BIND(m_mouthOpen);
		LUA_BIND(m_eyeTracking);
		LUA_BINDE(BlushLines, *(_self->GetBlushLines()));
		LUA_BINDE(Blush, *(_self->GetBlush()));
#undef LUA_CLASS
	};
};

