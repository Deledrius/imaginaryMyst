#include "imEnvironment.h"
#include "../imCommon.h"
#include "imSceneIndex.h"

bool imEnvironment::read(imStream* stream, imSceneIndex* idx)
{
    if (stream->read32() != 0x3e9b13da) {
        imLog("Error: Invalid Environment magic!");
        return false;
    }
    stream->read32();   // Data size

    m_keys.read(stream);
    imLog("DEBUG: [SDB] [ENVIRONMENT] '%s' (%u)", m_keys.self().name().data(),
          m_keys.refs().size());

    m_environFlags = stream->read32();
    if ((m_environFlags & kHas_200) != 0)
        imLog("DEBUG: [SDB] [ENVIRONMENT] (+14C) %f", stream->readFloat());
    if ((m_environFlags & kHasFogDepth) != 0)
        m_fogDepth = stream->readFloat();
    if ((m_environFlags & kHasFogDensity) != 0)
        m_fogDensity = stream->readFloat();
    if ((m_environFlags & kHasFogColor) != 0)
        m_fogColor.read(stream);
    if ((m_environFlags & kHasClearColor) != 0)
        m_clearColor.read(stream);
    if ((m_environFlags & kHasYon) != 0)
        m_yon = stream->readFloat();
    if ((m_environFlags & kHas_2) != 0) {
        imVector3 vec;
        vec.read(stream);
        imLog("DEBUG: [SDB] [ENVIRONMENT] (Vector3)");
    }
    if ((m_environFlags & kHas_4) != 0)
        imLog("DEBUG: [SDB] [ENVIRONMENT] (+130) %f", stream->readFloat());

    if ((m_environFlags & 0xA000) != 0) {
        imLog("ERROR: Environment flags 0x%X not currently supported",
              (m_environFlags & 0xA000));
        return false;
    }

    if ((m_environFlags & 0x7) == 7)
        m_material = idx->material(stream->read32());

    m_refs.resize(stream->read32());
    for (size_t i=0; i<m_refs.size(); i++)
        m_refs[i].read(stream);

    return true;
}
