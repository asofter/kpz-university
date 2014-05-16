using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab5
{
    class XmlReport : AbstractReport
    {
        public override void buildHeader(bool tooOld = false)
        {
            this.content = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n<root>\r\n";

            this.content += "<header tooOld=\"" + tooOld + "\">" + doc.name + " " + doc.author + " " + doc.year + "</header>\r\n";
        }

        public override void buildBody(bool tooSmart = false)
        {
            this.content += "<content tooSmart=\"" + tooSmart + "\">" + doc.content + "</content>\r\n";
        }

        public override void buildFooter()
        {

            this.content += "<countOfBodySymbols>" + doc.countOfBodySymbols + "</countOfBodySymbols>\r\n";
            this.content += "<countOfBodyWords>" + doc.countOfBodyWords + "</countOfBodyWords>\r\n";
            this.content += "</root>";
        }
    }
}
