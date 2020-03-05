#include <iostream>

#include <boost/filesystem.hpp>

// #define GOOGLE_STRIP_LOG 1 // отключить логирование сообщений ниже заданного уровня строгости
#include <glog/logging.h>

using namespace std;
namespace fs = boost::filesystem;

void InitGlog(const std::string& program)
{
    // Initialize Google's logging library.
    auto program_path = fs::path(program).remove_filename();
    auto logs_path = program_path.append("/logs/");
    if (!fs::is_directory(logs_path) || !fs::exists(logs_path)) // Check if src folder exists
        fs::create_directory(logs_path); // create src folder

    auto log_name = "pipeline";
    auto log_filename = logs_path.string() + log_name + ".INFO";
    auto wf_filename = logs_path.string() + log_name + ".WARN";
    auto ef_filename = logs_path.string() + log_name + ".ERR";

    ::google::SetLogDestination(google::INFO, log_filename.c_str());
    ::google::SetLogDestination(google::WARNING, wf_filename.c_str());
    ::google::SetLogDestination(google::ERROR, ef_filename.c_str());
    ::google::SetLogDestination(google::FATAL, "");

    ::google::SetLogSymlink(google::INFO, log_name);
    ::google::SetLogSymlink(google::WARNING, log_name);
    ::google::SetLogSymlink(google::ERROR, log_name);
    ::google::SetLogSymlink(google::FATAL, "");

    google::InitGoogleLogging(program.c_str());
}

int main(int , char** argv)
{
    InitGlog(argv[0]);

    LOG(INFO) << "Start pipeline programm";
    LOG(WARNING) << "Start pipeline programm";
    LOG(ERROR) << "Start pipeline programm";
    DLOG(INFO) << "Logging only for debug version";
    cout << "Hello World" << endl;
    return 0;
}
