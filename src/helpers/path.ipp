namespace helpers {
    template<typename ...Ts>
    std::string path::join(const std::string &first, const Ts &... other) {
        std::string result = first + m_delimiter + join(other...);
        remove_double_delimiter(result);
        return result;
    }
}