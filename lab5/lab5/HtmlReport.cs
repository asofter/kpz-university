using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab5
{
    class HtmlReport : AbstractReport
    {
        public override void buildHeader(bool tooOld = false)
        {
            this.content = "<html>\r\n<head>\r\n<title>" + doc.name + "</title>\r\n</head>\r\n<body>\r\n";

            this.content += "<div data-type=\"header\">\r\n";
            this.content += "<span data-attr=\"name\">" + doc.name + "</span>  \r\n";
            this.content += "<span data-attr=\"author\">" + doc.author + "</span>  \r\n";
            if (tooOld)
            {
                this.content += "<span data-attr=\"year\" style=\"color:red;\">" + doc.year + "</span>  \r\n";
            }
            else
            {
                this.content += "<span data-attr=\"year\">" + doc.year + "</span>  \r\n";
            }

            this.content += "</div>\r\n";
        }

        public override void buildBody(bool tooSmart = false)
        {
            this.content += "<div data-type=\"content\">\r\n";
            if (tooSmart)
            {
                this.content += "<span data-attr=\"content\" style=\"font-weight:bold;\">" + doc.content + "</span>  \r\n";
            }
            else
            {
                this.content += "<span data-attr=\"content\">" + doc.content + "</span>&nbsp;\r\n";
            }        
            this.content += "</div>\r\n";
        }

        public override void buildFooter()
        {
            this.content += "<div data-type=\"footer\">\r\n";
            this.content += "<span data-attr=\"countOfBodySymbols\">" + doc.countOfBodySymbols + "</span>  \r\n";
            this.content += "<span data-attr=\"countOfBodyWords\">" + doc.countOfBodyWords + "</span>\r\n";
            this.content += "</div>\r\n";
            this.content += "</body>\r\n</html>";
        }
    }
}
