#pragma once

#include <fstream>
#include <ostream>

namespace naval {

class ISink {
 public:
  virtual std::ostream& GetStream() = 0;
  virtual ~ISink() = default;
};

class OutputStreamSink : public ISink {
 public:
  explicit OutputStreamSink(std::ostream& stream) : stream_{stream} {
  }

  std::ostream& GetStream() override {
    return stream_;
  }

 private:
  std::ostream& stream_;
};

class FileStreamSink : public ISink {
 public:
  explicit FileStreamSink(const std::string& path) : stream_{path, std::ios::binary} {
    if (!stream_) {
      throw std::runtime_error("could not open file " + path);
    }
  }

  std::ostream& GetStream() override {
    return stream_;
  }

 private:
  std::ofstream stream_;
};

}  // namespace naval
