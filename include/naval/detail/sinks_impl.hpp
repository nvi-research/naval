#pragma once

#include <fstream>

#include <naval/sink.hpp>

namespace naval::detail {

class NullLikeSink : public ISink {
 public:
  void WriteBytes(const uint8_t* /*data*/, size_t /*count*/) override {
  }

  void Flush() override {
  }
};

class FileSink : public ISink {
 public:
  explicit FileSink(const std::string& path) : stream_{path, std::ios::binary} {
    if (!stream_) {
      throw std::runtime_error("could not open file " + path);
    }
  }

  void WriteBytes(const uint8_t* data, size_t count) override {
    stream_.write(reinterpret_cast<const char*>(data), static_cast<std::streamsize>(count));
  }

  void Flush() override {
    stream_.flush();
  }

 private:
  std::ofstream stream_;
};

class StdOStreamSink : public ISink {
 public:
  explicit StdOStreamSink(std::ostream& stream) : stream_{stream} {
  }

  void WriteBytes(const uint8_t* data, size_t count) override {
    stream_.write(reinterpret_cast<const char*>(data), static_cast<std::streamsize>(count));
  }

  void Flush() override {
    stream_.flush();
  }

 private:
  std::ostream& stream_;
};

};  // namespace naval::detail
