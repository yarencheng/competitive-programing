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
                        dir ('build') {
                            sh "cmake .."
                        }
                    }
                }
                stage('make') {
                    steps {
                        dir ('build') {
                            sh "make"
                        }
                    }
                }
                stage('make test') {
                    steps {
                        dir ('build') {
                            sh "make test"
                        }
                    }
                }
            }
        }
    }
}