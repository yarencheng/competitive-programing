def podYaml = '''
apiVersion: v1
kind: Pod
spec:
  containers:
  - name: gcc
    image: rikorose/gcc-cmake
    tty: true
    resources:
      limits:
        memory: 1Gi
      requests:
        cpu: 100m
        memory: 1Gi
'''

pipeline {
    agent {
        kubernetes {
            label "job-${UUID.randomUUID().toString()}"
            defaultContainer 'gcc'
            yaml "${podYaml}"
        }
    }
    stages {
        stage('cpp') {
            stages {
                stage('cmake') {
                    steps {
                        dir ('cpp/build') {
                            sh "cmake .."
                        }
                    }
                }
                stage('make') {
                    steps {
                        dir ('cpp/build') {
                            sh "make"
                        }
                    }
                }
                stage('make test') {
                    steps {
                        dir ('cpp/build') {
                            sh "ctest --verbose"
                        }
                    }
                }
            }
        }
    }
}