using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter file name with data");
            string fileName = Console.ReadLine();
            Console.WriteLine("Enter output format (xml, text, html)");
            string outputFormat = Console.ReadLine();
            Console.WriteLine("File or console?");
            string outputType = Console.ReadLine();
            string outputFileName = "";
            if(outputType.Equals("file")) {
                Console.WriteLine("Enter output file name");
                outputFileName = Console.ReadLine();
            }

            Document doc = new Document();
            //doc.load("/Others/Education/KPZ/kpz-university/lab5/lab5/data.txt");
            doc.load(fileName);

            AbstractReport report = null;
            if(outputFormat == "text") {
                report = new TextReport();
            } else if(outputFormat == "xml") {
                report = new XmlReport();
            } else if(outputFormat == "html") {
                report = new HtmlReport();
            }

            if (report != null)
            {
                report.build(doc);
                if (outputType == "file")
                {
                    report.writeToFile(outputFileName);
                }
                else
                {
                    report.writeToConsole();
                } 
            }

            Console.ReadLine();
        }
    }
}
