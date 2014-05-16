using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab5
{
    class TextReport : AbstractReport
    {
        public override void buildHeader(bool tooOld = false) 
        {
            this.content = doc.name + " " + doc.author + " " + doc.year;
            if (tooOld)
            {
                this.content += " #старий";
            }
            this.content += "\r\n";
        }

        public override void buildBody(bool tooSmart = false)
        {
            this.content += doc.content;
            if (tooSmart)
            {
                this.content += " #за розумний";
            }

            this.content += "\r\n";
        }

        public override void buildFooter()
        {
            this.content += doc.countOfBodySymbols + " " + doc.countOfBodyWords;
        }
    }
}
