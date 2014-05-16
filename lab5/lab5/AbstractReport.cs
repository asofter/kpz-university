using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace lab5
{
    abstract class AbstractReport
    {
        public Document doc;
        public string content;

        abstract public void buildHeader(bool tooOld = false);
        abstract public void buildBody(bool tooSmart = false);
        abstract public void buildFooter();

        public void build(Document document)
        {
            this.doc = document;
            bool tooOld = (doc.year < 2005) ? true : false;
            buildHeader(tooOld);
            bool tooSmart = (doc.countOfBodySymbols / doc.countOfBodyWords >= 7) ? true : false;
            buildBody(tooSmart);
            buildFooter();
        }

        public string getContent()
        {
            return this.content;
        }

        public void writeToConsole()
        {
            Console.WriteLine(this.getContent());
        }

        public void writeToFile(string fileName)
        {
            System.IO.StreamWriter file = new System.IO.StreamWriter(fileName);
            file.WriteLine(this.getContent());
            file.Close();
        }
    }
}
