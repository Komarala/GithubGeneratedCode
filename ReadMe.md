<p align=center>
    <b><span style="font-size: 24px">GitHub Copilot Generated Code</span></b>
</p>

# Log : 
- This code is written by AI coding assistance Github Copilot.
- Documentation and Test reports are also Github generated and updated in respective folders.
- This tool can only be used for assisting the developer but not for writing code from the base requirement.
- Requirement has to be broken down as small as possible for satisfactory results.
- 

# Metrics :
- Development Time:     2h
- Testing Time:         0.75h
- Documentation Time:   0.25h
- Code Complexity:      {using clang-tidy}
- Memory Usage:         {using valgrind for dynamic check}
- Interpretability:     This is user experience
- User experience:      This is user experience

# CLI
-  clang-tidy  ./GithubBowling.cpp --config-file=../.clang-tidy -p build | grep "threshold" > metrics/GithubBowling.log
-  valgrind --tool=massif ./main
- massif-visualizer ./metrics/massif.out.%PID%