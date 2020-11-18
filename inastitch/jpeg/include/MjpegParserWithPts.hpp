// Copyright (C) 2020 Inatech srl
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// Boost includes:
#include <boost/asio/thread_pool.hpp>

// Std includes:
#include <tuple>
#include <string>
#include <fstream>

namespace inastitch {
namespace jpeg {

class MjpegParser;

class MjpegParserWithPts
{
public:
    MjpegParserWithPts(std::string filename, uint32_t maxJpegBufferSize);
    ~MjpegParserWithPts();

public:
    std::tuple<uint8_t*, uint32_t, uint64_t> getFrame(uint32_t index);

private:
    const int ptsCount;
    std::ifstream m_ptsFile;
    uint64_t* const m_timestampArray;
    uint32_t m_currentPtsIndex = 0;

private:
    std::unique_ptr<MjpegParser> m_mjpegParser;
};


} // namespace jpeg
} // namespace inastitch
