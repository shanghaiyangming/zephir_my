namespace My\Utils;

/**
 * 用于处理URL或者文件路径资源到某个临时文件并返回内容或者resource
 * 
 * @author Young
 * @example 
 * 
 * obj = new iTemp("d:/1.txt");
 * obj->getResource();
 * 
 * obj = new iTemp("http://www.baidu.com");
 * obj->getBytes();
 * 
 */
class Temp
{

    private _tempFile = null;

    private _fp;

    private _bytes;

    public function __construct(url)
    {
        var context = null,
            opts;
        if filter_var(url, FILTER_VALIDATE_URL) {
            let opts = [
                "http" : [
                    "follow_location" : 3,
                    "max_redirects" : 3,
                    "timeout" : 5,
                    "method" : "GET",
                    "header" : "Connection: close\r\n",
                    "user_agent" : "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36"
                ]
            ];
            let context = stream_context_create(opts);
        }
        let this->_bytes = file_get_contents(url, false, context);
    }

    /**
     * 将请求资源保存，并返回resource
     *
     * @return resource
     */
    public function getResource()
    {
        let this->_tempFile = tempnam(sys_get_temp_dir(), "icc_temp_");
        file_put_contents(this->_tempFile, this->_bytes);
        return fopen(this->_tempFile, "r");
    }

    /**
     * 将请求资源存储在本地临时文件用于调用
     *
     * @return string
     */
    public function getBytes()
    {
        return this->_bytes;
    }

    public function __destruct()
    {
        if this->_tempFile != null {
            unlink(this->_tempFile);
        }
    }
}