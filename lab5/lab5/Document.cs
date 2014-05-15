using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab5
{
    class Document
    {
        public string author;
        public string name;
        public int year;
        public string content;
        public int countOfBodySymbols = 0;
        public int countOfBodyWords = 0;

        public AbstractReport build(Document document) { 
            this.doc = document; 
            bool tooOld = false;
            // (doc.Year < 2005) ? true : false; 
            buildHeader(tooOld); bool tooSmart = true;// (doc.countOfBodySymbols / doc.countOfBodyWords >= 7) ? true : false; 
            buildBody(tooSmart); 
            buildFooter(); 
            return report; 
        }
    }
}
