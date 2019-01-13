using System;
using System.Collections.Generic;
using System.Text;

namespace Interpreter.View
{
    public class RunExample : Command
    {
        private Controller.MyController ctrl;
        public RunExample(string key, string desc, Controller.MyController ctr) : base(key, desc)
        {
            this.ctrl = ctr;
        }

        public override void execute()
        {

            try
            {
                ctrl.executeAllSteps();
            }
            catch (SystemException e)
            {
                Console.WriteLine(e.Message);
            }
        }

    }
}
